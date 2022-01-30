////#include <glad/glad.h>
////#include <GLFW/glfw3.h>
////
////#include <iostream>
////
////void framebuffer_size_callback(GLFWwindow* window, int width, int height);
////void processInput(GLFWwindow* window);
////
////// settings
////const unsigned int SCR_WIDTH = 800;
////const unsigned int SCR_HEIGHT = 600;
////
////
//////片段着色器
////const char* vertexShaderSource = "#version 330 core\n"
////"layout (location = 0) in vec3 aPos;\n"
////"void main()\n"
////"{\n"
////"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
////"}\0";
////const char* fragmentShaderSource = "#version 330 core\n"
////"out vec4 FragColor;\n"
////"void main()\n"
////"{\n"
////"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
////"}\n\0";
////
////int main()
////{
////    // glfw: initialize and configure
////    // ------------------------------
////    glfwInit();
////    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
////    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
////    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
////
////#ifdef __APPLE__
////    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
////#endif
////
////    // glfw window creation
////    // --------------------
////    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
////    if (window == NULL)
////    {
////        std::cout << "Failed to create GLFW window" << std::endl;
////        glfwTerminate();
////        return -1;
////    }
////    glfwMakeContextCurrent(window);
////    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
////
////    // glad: load all OpenGL function pointers
////    // ---------------------------------------
////    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
////    {
////        std::cout << "Failed to initialize GLAD" << std::endl;
////        return -1;
////    }
////
////
////    // build and compile our shader program
////    // ------------------------------------
////    // vertex shader
////    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
////    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
////    glCompileShader(vertexShader);
////    // check for shader compile errors
////    int success;
////    char infoLog[512];
////    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
////    if (!success)
////    {
////        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
////        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
////    }
////    // fragment shader
////    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
////    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
////    glCompileShader(fragmentShader);
////    // check for shader compile errors
////    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
////    if (!success)
////    {
////        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
////        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
////    }
////    // link shaders
////    unsigned int shaderProgram = glCreateProgram();     
////    glAttachShader(shaderProgram, vertexShader);
////    glAttachShader(shaderProgram, fragmentShader);
////    glLinkProgram(shaderProgram);
////    // check for linking errors
////    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
////    if (!success) {
////        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
////        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
////    }
////    glDeleteShader(vertexShader);
////    glDeleteShader(fragmentShader);
////
////    // set up vertex data (and buffer(s)) and configure vertex attributes
////    // ------------------------------------------------------------------
////    //标准化设备坐标
////    float vertices[] = {
////         0.5f,  0.5f, 0.0f,  // top right
////         0.5f, -0.5f, 0.0f,  // bottom right
////        -0.5f, -0.5f, 0.0f,  // bottom left
////        -0.5f,  0.5f, 0.0f   // top left 
////    };
////    unsigned int indices[] = {  // note that we start from 0!
////        0, 1, 3,  // first Triangle
////        1, 2, 3   // second Triangle
////    };
////    unsigned int VBO, VAO, EBO;
////    glGenVertexArrays(1, &VAO);
////
////    //使用glGenBuffers函数和一个缓冲ID生成一个VBO对象
////    glGenBuffers(1, &VBO);
////    glGenBuffers(1, &EBO);
////    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
////    glBindVertexArray(VAO);
////
////    //GL_ARRAY_BUFFER。OpenGL允许我们同时绑定多个缓冲，
////    //只要它们是不同的缓冲类型。我们可以使用glBindBuffer函数
////    //把新创建的缓冲绑定到GL_ARRAY_BUFFER目标上
////    glBindBuffer(GL_ARRAY_BUFFER, VBO);
////    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
////
////    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
////    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
////
////    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
////    glEnableVertexAttribArray(0);
////
////    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
////    glBindBuffer(GL_ARRAY_BUFFER, 0);
////
////    // remember: do NOT unbind the EBO while a VAO is active as the bound element buffer object IS stored in the VAO; keep the EBO bound.
////    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
////
////    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
////    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
////    glBindVertexArray(0);
////
////
////    // uncomment this call to draw in wireframe polygons.
////    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
////
////    // render loop
////    // -----------
////    while (!glfwWindowShouldClose(window))
////    {
////        // input
////        // -----
////        processInput(window);
////
////        // render
////        // ------
////        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
////        glClear(GL_COLOR_BUFFER_BIT);
////
////        // draw our first triangle
////        glUseProgram(shaderProgram);
////        glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
////        //glDrawArrays(GL_TRIANGLES, 0, 6);
////        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
////        // glBindVertexArray(0); // no need to unbind it every time 
////
////        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
////        // -------------------------------------------------------------------------------
////        glfwSwapBuffers(window);
////        glfwPollEvents();
////    }
////
////    // optional: de-allocate all resources once they've outlived their purpose:
////    // ------------------------------------------------------------------------
////    glDeleteVertexArrays(1, &VAO);
////    glDeleteBuffers(1, &VBO);
////    glDeleteBuffers(1, &EBO);
////    glDeleteProgram(shaderProgram);
////
////    // glfw: terminate, clearing all previously allocated GLFW resources.
////    // ------------------------------------------------------------------
////    glfwTerminate();
////    return 0;
////}
////
////// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
////// ---------------------------------------------------------------------------------------------------------
////void processInput(GLFWwindow* window)
////{
////    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
////        glfwSetWindowShouldClose(window, true);
////}
////
////// glfw: whenever the window size changed (by OS or user resize) this callback function executes
////// ---------------------------------------------------------------------------------------------
////void framebuffer_size_callback(GLFWwindow* window, int width, int height)
////{
////    // make sure the viewport matches the new window dimensions; note that width and 
////    // height will be significantly larger than specified on retina displays.
////    glViewport(0, 0, width, height);
////}
////
//// 
//// //----------------------------------------------------------------------------------------------------------
//// //作业1
////#include <glad/glad.h>
////#include <GLFW/glfw3.h>
////
////#include <iostream>
////
////void framebuffer_size_callback(GLFWwindow* window, int width, int height);
////void processInput(GLFWwindow* window);
////
////// settings
////const unsigned int SCR_WIDTH = 800;
////const unsigned int SCR_HEIGHT = 600;
////
////const char* vertexShaderSource = "#version 330 core\n"
////"layout (location = 0) in vec3 aPos;\n"
////"void main()\n"
////"{\n"
////"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
////"}\0";
////const char* fragmentShaderSource = "#version 330 core\n"
////"out vec4 FragColor;\n"
////"void main()\n"
////"{\n"
////"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
////"}\n\0";
////
////int main()
////{
////	// glfw: initialize and configure
////	// ------------------------------
////	glfwInit();
////	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
////	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
////	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
////
////#ifdef __APPLE__
////	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
////#endif
////
////	// glfw window creation
////	// --------------------
////	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
////	if (window == NULL)
////	{
////		std::cout << "Failed to create GLFW window" << std::endl;
////		glfwTerminate();
////		return -1;
////	}
////	glfwMakeContextCurrent(window);
////	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
////
////	// glad: load all OpenGL function pointers
////	// ---------------------------------------
////	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
////	{
////		std::cout << "Failed to initialize GLAD" << std::endl;
////		return -1;
////	}
////
////
////	// build and compile our shader program
////	// ------------------------------------
////	// vertex shader
////	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
////	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
////	glCompileShader(vertexShader);
////	// check for shader compile errors
////	int success;
////	char infoLog[512];
////	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
////	if (!success)
////	{
////		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
////		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
////	}
////	// fragment shader
////	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
////	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
////	glCompileShader(fragmentShader);
////	// check for shader compile errors
////	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
////	if (!success)
////	{
////		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
////		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
////	}
////	// link shaders
////	unsigned int shaderProgram = glCreateProgram();
////	glAttachShader(shaderProgram, vertexShader);
////	glAttachShader(shaderProgram, fragmentShader);
////	glLinkProgram(shaderProgram);
////	// check for linking errors
////	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
////	if (!success) {
////		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
////		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
////	}
////	glDeleteShader(vertexShader);
////	glDeleteShader(fragmentShader);
////
////	// set up vertex data (and buffer(s)) and configure vertex attributes
////	// ------------------------------------------------------------------
////	float vertices[] = {
////		-0.5f, -0.5f, 0.0f, // left  
////		 0.5f, -0.5f, 0.0f, // right 
////		 0.0f,  0.5f, 0.0f,  // top   
////
////		 0.0f, 0.5f, 0.0f,
////		 0.5f, -0.5f, 0.0f,
////		 1.0f, 0.5f, 0.0f
////	};
////
////	unsigned int VBO, VAO;
////	glGenVertexArrays(1, &VAO);
////	glGenBuffers(1, &VBO);
////	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
////	glBindVertexArray(VAO);
////
////	glBindBuffer(GL_ARRAY_BUFFER, VBO);
////	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
////
////	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
////	glEnableVertexAttribArray(0);
////
////	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
////	glBindBuffer(GL_ARRAY_BUFFER, 0);
////
////	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
////	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
////	glBindVertexArray(0);
////
////
////	// uncomment this call to draw in wireframe polygons.
////	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
////
////	// render loop
////	// -----------
////	while (!glfwWindowShouldClose(window))
////	{
////		// input
////		// -----
////		processInput(window);
////
////		// render
////		// ------
////		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
////		glClear(GL_COLOR_BUFFER_BIT);
////
////		// draw our first triangle
////		glUseProgram(shaderProgram);
////		glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
////		glDrawArrays(GL_TRIANGLES, 0, 6);
////		// glBindVertexArray(0); // no need to unbind it every time 
////
////		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
////		// -------------------------------------------------------------------------------
////		glfwSwapBuffers(window);
////		glfwPollEvents();
////	}
////
////	// optional: de-allocate all resources once they've outlived their purpose:
////	// ------------------------------------------------------------------------
////	glDeleteVertexArrays(1, &VAO);
////	glDeleteBuffers(1, &VBO);
////	glDeleteProgram(shaderProgram);
////
////	// glfw: terminate, clearing all previously allocated GLFW resources.
////	// ------------------------------------------------------------------
////	glfwTerminate();
////	return 0;
////}
////
////// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
////// ---------------------------------------------------------------------------------------------------------
////void processInput(GLFWwindow* window)
////{
////	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
////		glfwSetWindowShouldClose(window, true);
////}
////
////// glfw: whenever the window size changed (by OS or user resize) this callback function executes
////// ---------------------------------------------------------------------------------------------
////void framebuffer_size_callback(GLFWwindow* window, int width, int height)
////{
////	// make sure the viewport matches the new window dimensions; note that width and 
////	// height will be significantly larger than specified on retina displays.
////	glViewport(0, 0, width, height);
////}
//
////作业二
//
//
////#include <glad/glad.h>
////#include <GLFW/glfw3.h>
////
////#include <iostream>
////
////void framebuffer_size_callback(GLFWwindow* window, int width, int height);
////void processInput(GLFWwindow* window);
////
////// settings
////const unsigned int SCR_WIDTH = 800;
////const unsigned int SCR_HEIGHT = 600;
////
////const char* vertexShaderSource = "#version 330 core\n"
////"layout (location = 0) in vec3 aPos;\n"
////"void main()\n"
////"{\n"
////"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
////"}\0";
////const char* fragmentShaderSource = "#version 330 core\n"
////"out vec4 FragColor;\n"
////"void main()\n"
////"{\n"
////"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
////"}\n\0";
////
////int main()
////{
////	// glfw: initialize and configure
////	// ------------------------------
////	glfwInit();
////	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
////	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
////	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
////
////#ifdef __APPLE__
////	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
////#endif
////
////	// glfw window creation
////	// --------------------
////	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
////	if (window == NULL)
////	{
////		std::cout << "Failed to create GLFW window" << std::endl;
////		glfwTerminate();
////		return -1;
////	}
////	glfwMakeContextCurrent(window);
////	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
////
////	// glad: load all OpenGL function pointers
////	// ---------------------------------------
////	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
////	{
////		std::cout << "Failed to initialize GLAD" << std::endl;
////		return -1;
////	}
////
////
////	// build and compile our shader program
////	// ------------------------------------
////	// vertex shader
////	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
////	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
////	glCompileShader(vertexShader);
////	// check for shader compile errors
////	int success;
////	char infoLog[512];
////	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
////	if (!success)
////	{
////		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
////		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
////	}
////	// fragment shader
////	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
////	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
////	glCompileShader(fragmentShader);
////	// check for shader compile errors
////	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
////	if (!success)
////	{
////		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
////		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
////	}
////	// link shaders
////	unsigned int shaderProgram = glCreateProgram();
////	glAttachShader(shaderProgram, vertexShader);
////	glAttachShader(shaderProgram, fragmentShader);
////	glLinkProgram(shaderProgram);
////	// check for linking errors
////	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
////	if (!success) {
////		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
////		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
////	}
////	glDeleteShader(vertexShader);
////	glDeleteShader(fragmentShader);
////
////	// set up vertex data (and buffer(s)) and configure vertex attributes
////	// ------------------------------------------------------------------
////	float firstTriangle[] = {
////		-0.9f, -0.5f, 0.0f,  // left 
////		-0.0f, -0.5f, 0.0f,  // right
////		-0.45f, 0.5f, 0.0f,  // top 
////	};
////	float secondTriangle[] = {
////		0.0f, -0.5f, 0.0f,  // left
////		0.9f, -0.5f, 0.0f,  // right
////		0.45f, 0.5f, 0.0f   // top 
////	};
////	unsigned int VBO[2], VAO[2];
////	glGenVertexArrays(2, VAO);
////	glGenBuffers(2, VBO);
////	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
////	glBindVertexArray(VAO[0]);
////	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
////	glBufferData(GL_ARRAY_BUFFER, sizeof(firstTriangle), firstTriangle, GL_STATIC_DRAW);
////	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
////	glEnableVertexAttribArray(0);
////
////	glBindVertexArray(VAO[1]);
////	glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
////	glBufferData(GL_ARRAY_BUFFER, sizeof(secondTriangle), secondTriangle, GL_STATIC_DRAW);
////	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
////	glEnableVertexAttribArray(0);
////	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
////	
////	
////	glBindBuffer(GL_ARRAY_BUFFER, 0);
////	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
////	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
////	glBindVertexArray(0);
////
////
////	// uncomment this call to draw in wireframe polygons.
////	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
////
////	// render loop
////	// -----------
////	while (!glfwWindowShouldClose(window))
////	{
////		// input
////		// -----
////		processInput(window);
////
////		// render
////		// ------
////		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
////		glClear(GL_COLOR_BUFFER_BIT);
////
////		// draw our first triangle
////		glUseProgram(shaderProgram);
////		glBindVertexArray(VAO[0]); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
////		glDrawArrays(GL_TRIANGLES, 0, 3);
////
////		glBindVertexArray(VAO[1]); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
////		glDrawArrays(GL_TRIANGLES, 0, 3);
////		// glBindVertexArray(0); // no need to unbind it every time 
////
////		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
////		// -------------------------------------------------------------------------------
////		glfwSwapBuffers(window);
////		glfwPollEvents();
////	}
////
////	// optional: de-allocate all resources once they've outlived their purpose:
////	// ------------------------------------------------------------------------
////	glDeleteVertexArrays(2,VAO);
////	glDeleteBuffers(2, VBO);
////
////	glDeleteProgram(shaderProgram);
////
////	// glfw: terminate, clearing all previously allocated GLFW resources.
////	// ------------------------------------------------------------------
////	glfwTerminate();
////	return 0;
////}
////
////// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
////// ---------------------------------------------------------------------------------------------------------
////void processInput(GLFWwindow* window)
////{
////	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
////		glfwSetWindowShouldClose(window, true);
////}
////
////// glfw: whenever the window size changed (by OS or user resize) this callback function executes
////// ---------------------------------------------------------------------------------------------
////void framebuffer_size_callback(GLFWwindow* window, int width, int height)
////{
////	// make sure the viewport matches the new window dimensions; note that width and 
////	// height will be significantly larger than specified on retina displays.
////	glViewport(0, 0, width, height);
////}
//
////作业三
//
//
//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//
//#include <iostream>
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void processInput(GLFWwindow* window);
//
//// settings
//const unsigned int SCR_WIDTH = 800;
//const unsigned int SCR_HEIGHT = 600;
//
//const char* vertexShaderSource = "#version 330 core\n"
//"layout (location = 0) in vec3 aPos;\n"
//"void main()\n"
//"{\n"
//"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//"}\0";
//const char* fragmentShaderSource = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"void main()\n"
//"{\n"
//"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
//"}\n\0";
//const char* fragmentShader2Source = "#version 330 core\n"
//"out vec4 FragColor;\n"
//"void main()\n"
//"{\n"
//"   FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);\n"
//"}\n\0";
//int main()
//{
//	// glfw: initialize and configure
//	// ------------------------------
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//#ifdef __APPLE__
//	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//#endif
//
//	// glfw window creation
//	// --------------------
//	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
//	if (window == NULL)
//	{
//		std::cout << "Failed to create GLFW window" << std::endl;
//		glfwTerminate();
//		return -1;
//	}
//	glfwMakeContextCurrent(window);
//	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//
//	// glad: load all OpenGL function pointers
//	// ---------------------------------------
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//	{
//		std::cout << "Failed to initialize GLAD" << std::endl;
//		return -1;
//	}
//
//
//	// build and compile our shader program
//	// ------------------------------------
//	// vertex shader
//	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
//	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//	glCompileShader(vertexShader);
//	// check for shader compile errors
//	int success;
//	char infoLog[512];
//	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
//	}
//	//1------yellow
//	// fragment shader
//	unsigned int fragmentShaderYellow = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragmentShaderYellow, 1, &fragmentShaderSource, NULL);
//	glCompileShader(fragmentShaderYellow);
//	// check for shader compile errors
//	glGetShaderiv(fragmentShaderYellow, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		glGetShaderInfoLog(fragmentShaderYellow, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
//	}
//	// link shaders
//	unsigned int shaderProgramYellow = glCreateProgram();
//	glAttachShader(shaderProgramYellow, vertexShader);
//	glAttachShader(shaderProgramYellow, fragmentShaderYellow);
//	glLinkProgram(shaderProgramYellow);
//	// check for linking errors
//	glGetProgramiv(shaderProgramYellow, GL_LINK_STATUS, &success);
//	if (!success) {
//		glGetProgramInfoLog(shaderProgramYellow, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
//	}
//	glDeleteShader(vertexShader);
//	glDeleteShader(fragmentShaderYellow);
//
//	//--------orange
//	// fragment shader
//	unsigned int fragmentShaderOrange = glCreateShader(GL_FRAGMENT_SHADER);
//	glShaderSource(fragmentShaderOrange, 1, &fragmentShader2Source, NULL);
//	glCompileShader(fragmentShaderOrange);
//	// check for shader compile errors
//	glGetShaderiv(fragmentShaderOrange, GL_COMPILE_STATUS, &success);
//	if (!success)
//	{
//		glGetShaderInfoLog(fragmentShaderOrange, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
//	}
//	// link shaders
//	unsigned int shaderProgramOrange = glCreateProgram();
//	glAttachShader(shaderProgramOrange, vertexShader);
//	glAttachShader(shaderProgramOrange, fragmentShaderOrange);
//	glLinkProgram(shaderProgramOrange);
//	// check for linking errors
//	glGetProgramiv(shaderProgramOrange, GL_LINK_STATUS, &success);
//	if (!success) {
//		glGetProgramInfoLog(shaderProgramOrange, 512, NULL, infoLog);
//		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
//	}
//	glDeleteShader(vertexShader);
//	glDeleteShader(fragmentShaderYellow);
//	glDeleteShader(fragmentShaderOrange);
//	// set up vertex data (and buffer(s)) and configure vertex attributes
//	// ------------------------------------------------------------------
//	float firstTriangle[] = {
//		-0.9f, -0.5f, 0.0f,  // left 
//		-0.0f, -0.5f, 0.0f,  // right
//		-0.45f, 0.5f, 0.0f,  // top 
//	};
//	float secondTriangle[] = {
//		0.0f, -0.5f, 0.0f,  // left
//		0.9f, -0.5f, 0.0f,  // right
//		0.45f, 0.5f, 0.0f   // top 
//	};
//	unsigned int VBO[2], VAO[2];
//	glGenVertexArrays(2, VAO);
//	glGenBuffers(2, VBO);
//	// bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
//	glBindVertexArray(VAO[0]);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(firstTriangle), firstTriangle, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	glBindVertexArray(VAO[1]);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(secondTriangle), secondTriangle, GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);
//	glEnableVertexAttribArray(0);
//	// note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
//
//
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	// You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
//	// VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
//	glBindVertexArray(0);
//
//	int nrAttributes;
//	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
//	std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;
//	// uncomment this call to draw in wireframe polygons.
//	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
//
//	// render loop
//	// -----------
//	while (!glfwWindowShouldClose(window))
//	{
//		// input
//		// -----
//		processInput(window);
//
//		// render
//		// ------
//		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT);
//
//		// draw our first triangle
//		glUseProgram(shaderProgramYellow);
//		glBindVertexArray(VAO[0]); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//
//		glUseProgram(shaderProgramOrange);
//		glBindVertexArray(VAO[1]); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
//		glDrawArrays(GL_TRIANGLES, 0, 3);
//		// glBindVertexArray(0); // no need to unbind it every time 
//
//		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
//		// -------------------------------------------------------------------------------
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	// optional: de-allocate all resources once they've outlived their purpose:
//	// ------------------------------------------------------------------------
//	glDeleteVertexArrays(2, VAO);
//	glDeleteBuffers(2, VBO);
//
//	glDeleteProgram(shaderProgramYellow);
//
//	// glfw: terminate, clearing all previously allocated GLFW resources.
//	// ------------------------------------------------------------------
//	glfwTerminate();
//	return 0;
//}
//
//// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
//// ---------------------------------------------------------------------------------------------------------
//void processInput(GLFWwindow* window)
//{
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//}
//
//// glfw: whenever the window size changed (by OS or user resize) this callback function executes
//// ---------------------------------------------------------------------------------------------
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	// make sure the viewport matches the new window dimensions; note that width and 
//	// height will be significantly larger than specified on retina displays.
//	glViewport(0, 0, width, height);
//}