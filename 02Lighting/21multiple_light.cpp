#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "CameraDirector.h"
#include "stb_image.h"

unsigned int loadTexture(const char *image);

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = 400.0f;
float lastY = 300.0f;
bool firstMouse = true;

float deltaTime = 0.0f;
float lastFrame = 0.0f;

glm::vec3 lightPos(0.5f, 0.5f, 2.0f);

int createProgram(const char* vertexSource, const char* fragmentSource);

const char* objectVertexSource = "#version 330 core \n"
    "layout (location = 0) in vec3 aPos; \n"
    "layout (location = 1) in vec3 aNormal; \n"
    "layout (location = 2) in vec2 aTexCoords; \n"
    "out vec2 TexCoords; \n"
    "out vec3 FragPos; \n"
    "out vec3 Normal; \n"
    "uniform mat4 model; \n"
    "uniform mat4 view; \n"
    "uniform mat4 projection; \n"
    "void main() { \n"
    "    TexCoords = aTexCoords; \n"
    "    FragPos = vec3(model * vec4(aPos, 1.0)); \n"
    "    Normal = mat3(transpose(inverse(model))) * aNormal; \n"
    "    gl_Position = projection * view * vec4(FragPos, 1.0); \n"
    "} \n";
const char* objectFragmentSource = "#version 330 core \n"
    "out vec4 FragColor; \n"
    "struct Material { \n"
    "    sampler2D diffuse; sampler2D specular; float shininess; \n"
    "}; \n"
    "struct DirLight { \n"
    "    vec3 direction; vec3 ambient; vec3 diffuse; vec3 specular; \n"
    "}; \n"
    "struct PointLight { \n"
    "    vec3 position; float constant; float linear; float quadratic; \n"
    "    vec3 ambient; vec3 diffuse; vec3 specular; \n"
    "}; \n"
    "struct SpotLight { \n"
    "    vec3 position; vec3 direction; float cutOff; float outerCutOff; \n"
    "    float constant; float linear; float quadratic; \n"
    "    vec3 ambient; vec3 diffuse; vec3 specular; \n"
    "}; \n"
    "in vec2 TexCoords; \n"
    "in vec3 Normal; \n"
    "in vec3 FragPos; \n"
    "uniform vec3 viewPos; \n"
    "uniform Material material; \n"
    "#define NR_POINT_LIGHTS 4 \n"
    "uniform DirLight dirLight; \n"
    "uniform PointLight pointLights[NR_POINT_LIGHTS]; \n"
    "uniform SpotLight spotLight; \n"
    "vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir); \n"
    "vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir); \n"
    "vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir); \n"
    "void main() { \n"
    "    vec3 norm = normalize(Normal); \n"
    "    vec3 viewDir = normalize(viewPos - FragPos); \n"
    "    vec3 result = CalcDirLight(dirLight, norm, viewDir); \n"
    "    for (int i = 0; i < NR_POINT_LIGHTS; i++) \n"
    "        result += CalcPointLight(pointLights[i], norm, FragPos, viewDir); \n"
    "    result += CalcSpotLight(spotLight, norm, FragPos, viewDir); \n"
    "    FragColor = vec4(result, 1.0); \n"
    "} \n"
    "vec3 CalcPointLight(PointLight light, vec3 normal, vec3 fragPos, vec3 viewDir) { \n"
    "    vec3 lightDir = normalize(light.position - fragPos); \n"
    "    float diff = max(dot(normal, lightDir), 0.0); \n"
    "    vec3 reflectDir = reflect(-lightDir, normal); \n"
    "    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess); \n"
    "    // attenuation \n"
    "    float distance = length(light.position - fragPos); \n"
    "    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance)); \n"
    "    vec3 ambient = light.ambient * vec3(texture(material.diffuse, TexCoords)); \n"
    "    vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, TexCoords)); \n"
    "    vec3 specular = light.specular * spec * vec3(texture(material.specular, TexCoords)); \n"
    "    ambient *= attenuation; \n"
    "    diffuse *= attenuation; \n"
    "    specular *= attenuation; \n"
    "    return (ambient + diffuse + specular); \n"
    "} \n"
    "vec3 CalcDirLight(DirLight light, vec3 normal, vec3 viewDir) { \n"
    "    vec3 lightDir = normalize(-light.direction); \n"
    "    float diff = max(dot(normal, lightDir), 0.0); \n"
    "    vec3 reflectDir = reflect(-lightDir, normal); \n"
    "    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess); \n"
    "    vec3 ambient = light.ambient * vec3(texture(material.diffuse, TexCoords)); \n"
    "    vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, TexCoords)); \n"
    "    vec3 specular = light.specular * spec * vec3(texture(material.specular, TexCoords)); \n"
    "    return (ambient + diffuse + specular); \n"
    "} \n"
    "vec3 CalcSpotLight(SpotLight light, vec3 normal, vec3 fragPos, vec3 viewDir) { \n"
    "    // ambient \n"
    "    vec3 ambient = light.ambient * vec3(texture(material.diffuse, TexCoords)); \n"
    "    // diffuse \n"
    "    vec3 norm = normalize(normal); \n"
    "    vec3 lightDir = normalize(light.position - FragPos); \n"
    "    float diff = max(dot(norm, lightDir), 0.0); \n"
    "    vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, TexCoords)); \n"
    "    // specular \n"
    "    viewDir = normalize(viewPos - FragPos); \n"
    "    vec3 reflectDir = reflect(-lightDir, norm); \n"
    "    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess); \n"
    "    vec3 specular = light.specular * spec * vec3(texture(material.specular, TexCoords)); \n"
    "    float theta = dot(lightDir, normalize(-light.direction)); \n"
    "    float epsilon = (light.cutOff - light.outerCutOff); \n"
    "    float intensity = clamp((theta - light.outerCutOff) / epsilon, 0.0, 1.0); \n"
    "    float distance = length(light.position - FragPos); \n"
    "    float attenuation = 1.0 / (light.constant + light.linear * distance + light.quadratic * (distance * distance)); \n"
    "    return (ambient + diffuse + specular) * attenuation * intensity; \n"
    "} \n";
const char* lightVertexSource = "#version 330 core \n"
    "layout (location = 0) in vec3 aPos; \n"
    "uniform mat4 model; \n"
    "uniform mat4 view; \n"
    "uniform mat4 projection; \n"
    "void main() { \n"
    "    gl_Position = projection * view * model * vec4(aPos, 1.0); \n"
    "} \n";
const char* lightFragmentSource = "#version 330 core \n"
    "out vec4 FragColor; \n"
    "void main() { \n"
    "    FragColor = vec4(1.0); \n"
    "} \n";

int main() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetScrollCallback(window, scroll_callback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    int objectProgram = createProgram(objectVertexSource, objectFragmentSource);
    int lightProgram = createProgram(lightVertexSource, lightFragmentSource);
    float vertices[] = {
        // positions          // normals           // texture coords
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f,  1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f,  0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f,  1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f,  0.0f,

        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
        -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
        -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  1.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f,  0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
         0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f,  1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  1.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f,  1.0f
    };
    glm::vec3 cubePositions[] = {
        glm::vec3( 0.0f,  0.0f,  0.0f),
        glm::vec3( 2.0f,  5.0f, -15.0f),
        glm::vec3(-1.5f, -2.2f, -2.5f),
        glm::vec3(-3.8f, -2.0f, -12.3f),
        glm::vec3( 2.4f, -0.4f, -3.5f),
        glm::vec3(-1.7f,  3.0f, -7.5f),
        glm::vec3( 1.3f, -2.0f, -2.5f),
        glm::vec3( 1.5f,  2.0f, -2.5f),
        glm::vec3( 1.5f,  0.2f, -1.5f),
        glm::vec3(-1.3f,  1.0f, -1.5f)
    };
    glm::vec3 pointLightPositions[] = {
        glm::vec3( 0.7f,  0.2f,  2.0f),
        glm::vec3( 2.3f, -3.3f, -4.0f),
        glm::vec3(-4.0f,  2.0f, -12.0f),
        glm::vec3( 0.0f,  0.0f, -3.0f)
    };
    unsigned int objectVAO, lightVAO, VBO;
    glGenVertexArrays(1, &objectVAO);
    glGenBuffers(1, &VBO);
    glBindVertexArray(objectVAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6*sizeof(float)));
    glEnableVertexAttribArray(2);

    glGenVertexArrays(1, &lightVAO);
    glBindVertexArray(lightVAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glEnable(GL_DEPTH_TEST);

    unsigned int diffuseMap = loadTexture("images/container2.png");
    unsigned int specularMap = loadTexture("images/container2_specular.png");
    glUseProgram(objectProgram);
    glUniform1i(glGetUniformLocation(objectProgram, "material.diffuse"), 0);
    glUniform1i(glGetUniformLocation(objectProgram, "material.specular"), 1);
    while (!glfwWindowShouldClose(window)) {
        float currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        processInput(window);

        // render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(objectProgram);
        glUniform3fv(glGetUniformLocation(objectProgram, "viewPos"), 1, &(camera.Position[0]));
        glUniform1f(glGetUniformLocation(objectProgram, "material.shininess"), 32.0f);

        // directional light
        glUniform3f(glGetUniformLocation(objectProgram, "dirLight.direction"), -0.2f, -1.0f, -0.3f);
        glUniform3f(glGetUniformLocation(objectProgram, "dirLight.ambient"), 0.05f, 0.05f, 0.05f);
        glUniform3f(glGetUniformLocation(objectProgram, "dirLight.diffuse"), 0.4f, 0.4f, 0.4f);
        glUniform3f(glGetUniformLocation(objectProgram, "dirLight.specular"), 0.5f, 0.5f, 0.5f);

        // point light 1
        glUniform3fv(glGetUniformLocation(objectProgram, "pointLights[0].position"), 1, &(pointLightPositions[0][0]));
        glUniform3f(glGetUniformLocation(objectProgram, "pointLights[0].ambient"), 0.05f, 0.05f, 0.05f);
        glUniform3f(glGetUniformLocation(objectProgram, "pointLights[0].diffuse"), 0.8f, 0.8f, 0.8f);
        glUniform3f(glGetUniformLocation(objectProgram, "pointLights[0].specular"), 1.0f, 1.0f, 1.0f);
        glUniform1f(glGetUniformLocation(objectProgram, "pointLights[0].constant"), 1.0f);
        glUniform1f(glGetUniformLocation(objectProgram, "pointLights[0].linear"), 0.09f);
        glUniform1f(glGetUniformLocation(objectProgram, "pointLights[0].quadratic"), 0.032f);
        // point light 2
        glUniform3fv(glGetUniformLocation(objectProgram, "pointLights[1].position"), 1, &(pointLightPositions[1][0]));
        glUniform3f(glGetUniformLocation(objectProgram, "pointLights[1].ambient"), 0.05f, 0.05f, 0.05f);
        glUniform3f(glGetUniformLocation(objectProgram, "pointLights[1].diffuse"), 0.8f, 0.8f, 0.8f);
        glUniform3f(glGetUniformLocation(objectProgram, "pointLights[1].specular"), 1.0f, 1.0f, 1.0f);
        glUniform1f(glGetUniformLocation(objectProgram, "pointLights[1].constant"), 1.0f);
        glUniform1f(glGetUniformLocation(objectProgram, "pointLights[1].linear"), 0.09f);
        glUniform1f(glGetUniformLocation(objectProgram, "pointLights[1].quadratic"), 0.032f);
        // point light 3
        glUniform3fv(glGetUniformLocation(objectProgram, "pointLights[2].position"), 1, &(pointLightPositions[2][0]));
        glUniform3f(glGetUniformLocation(objectProgram, "pointLights[2].ambient"), 0.05f, 0.05f, 0.05f);
        glUniform3f(glGetUniformLocation(objectProgram, "pointLights[2].diffuse"), 0.8f, 0.8f, 0.8f);
        glUniform3f(glGetUniformLocation(objectProgram, "pointLights[2].specular"), 1.0f, 1.0f, 1.0f);
        glUniform1f(glGetUniformLocation(objectProgram, "pointLights[2].constant"), 1.0f);
        glUniform1f(glGetUniformLocation(objectProgram, "pointLights[2].linear"), 0.09f);
        glUniform1f(glGetUniformLocation(objectProgram, "pointLights[2].quadratic"), 0.032f);
        // point light 4
        glUniform3fv(glGetUniformLocation(objectProgram, "pointLights[3].position"), 1, &(pointLightPositions[3][0]));
        glUniform3f(glGetUniformLocation(objectProgram, "pointLights[3].ambient"), 0.05f, 0.05f, 0.05f);
        glUniform3f(glGetUniformLocation(objectProgram, "pointLights[3].diffuse"), 0.8f, 0.8f, 0.8f);
        glUniform3f(glGetUniformLocation(objectProgram, "pointLights[3].specular"), 1.0f, 1.0f, 1.0f);
        glUniform1f(glGetUniformLocation(objectProgram, "pointLights[3].constant"), 1.0f);
        glUniform1f(glGetUniformLocation(objectProgram, "pointLights[3].linear"), 0.09f);
        glUniform1f(glGetUniformLocation(objectProgram, "pointLights[3].quadratic"), 0.032f);

        // spot light
        glUniform3fv(glGetUniformLocation(objectProgram, "spotLight.position"), 1, &(camera.Position[0]));
        glUniform3fv(glGetUniformLocation(objectProgram, "spotLight.direction"), 1, &(camera.Front[0]));
        glUniform3f(glGetUniformLocation(objectProgram, "spotLight.ambient"), 0.0f, 0.0f, 0.0f);
        glUniform3f(glGetUniformLocation(objectProgram, "spotLight.diffuse"), 1.0f, 1.0f, 1.0f);
        glUniform3f(glGetUniformLocation(objectProgram, "spotLight.specular"), 1.0f, 1.0f, 1.0f);
        glUniform1f(glGetUniformLocation(objectProgram, "spotLight.constant"), 1.0f);
        glUniform1f(glGetUniformLocation(objectProgram, "spotLight.linear"), 0.09f);
        glUniform1f(glGetUniformLocation(objectProgram, "spotLight.quadratic"), 0.032f);
        glUniform1f(glGetUniformLocation(objectProgram, "spotLight.cutOff"), glm::cos(glm::radians(12.5f)));
        glUniform1f(glGetUniformLocation(objectProgram, "spotLight.outerCutOff"), glm::cos(glm::radians(15.0f)));

        glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), 4.0f/3.0f, 0.1f, 100.0f);
        glm::mat4 view = camera.getViewMatrix();
        glBindVertexArray(objectVAO);
        for (unsigned int i = 0; i < 10; i++) {
            glm::mat4 model;
            model = glm::translate(model, cubePositions[i]);
            float angle = 20.0f * i;
            model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
            glUniformMatrix4fv(glGetUniformLocation(objectProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }
        glUniformMatrix4fv(glGetUniformLocation(objectProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
        glUniformMatrix4fv(glGetUniformLocation(objectProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
        
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, diffuseMap);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, specularMap);

        glUseProgram(lightProgram);
        glUniformMatrix4fv(glGetUniformLocation(lightProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
        glUniformMatrix4fv(glGetUniformLocation(lightProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
        glBindVertexArray(lightVAO);
        for (unsigned int i = 0; i < 4; i++) {
            glm::mat4 model;
            model = glm::mat4();
            model = glm::translate(model, pointLightPositions[i]);
            model = glm::scale(model, glm::vec3(0.2f));
            glUniformMatrix4fv(glGetUniformLocation(lightProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
            glDrawArrays(GL_TRIANGLES, 0, 36);
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &objectVAO);
    glDeleteVertexArrays(1, &lightVAO);
    glDeleteBuffers(1, &VBO);
    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow* window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    
    float cameraSpeed = 2.5 * deltaTime;
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.processKeyboard(FORWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.processKeyboard(BACKWARD, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.processKeyboard(LEFT, deltaTime);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.processKeyboard(RIGHT, deltaTime);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void mouse_callback(GLFWwindow* window, double xpos, double ypos) {
    if (firstMouse) {
        lastX = xpos;
        lastY = ypos;
        firstMouse =false;
    }

    float xoffset = xpos - lastX;
    // reversed since y-coordinates go from bottom to top
    float yoffset = lastY - ypos;
    lastX = xpos;
    lastY = ypos;

    camera.processMouseMovement(xoffset, yoffset);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
    camera.processMouseScroll(yoffset);
}

int createProgram(const char* vertexSource, const char* fragmentSource) {
    int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);

    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "Error::Shader::Vertex::Compilation_Failed\n" << infoLog << std::endl;
    }
    int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "Error::Shader::Fragment::Compilation_Failed\n" << infoLog << std::endl;
    }
    int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "Error::Shader::Program::Linking_Failed\n" << infoLog << std::endl;
    }
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    return shaderProgram;
}

unsigned int loadTexture(const char *image) {
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture); 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true);
    unsigned char *data = stbi_load(image, &width, &height, &nrChannels, 0);
    if (data) {
        GLenum format;
        if (nrChannels == 1) {
            format = GL_RED;
        } else if (nrChannels == 3) {
            format = GL_RGB;
        } else if (nrChannels == 4) {
            format = GL_RGBA;
        }
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
    return texture;
}