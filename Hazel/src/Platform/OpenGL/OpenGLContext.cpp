#include "hzpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

namespace Hazel
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		HZ_CORE_ASSERT(windowHandle, "window handle is null!");
	}

	OpenGLContext::~OpenGLContext()
	{
	}

	void OpenGLContext::Init()
	{
		HZ_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		HZ_CORE_ASSERT(status, "Failed to initialize Glad!");
		
		char verdor[64], renderer[64], version[64];

		sprintf_s(verdor, "%s", glGetString(GL_VENDOR));
		sprintf_s(renderer, "%s", glGetString(GL_RENDERER));
		sprintf_s(version, "%s", glGetString(GL_VERSION));
		HZ_CORE_INFO("OpenGL Info:");
		HZ_CORE_INFO(" Vendor:   {0}", verdor);
		HZ_CORE_INFO(" Renderer: {0}", renderer);
		HZ_CORE_INFO(" Version:  {0}", version);

	#ifdef HZ_ENABLE_ASSERTS
		int versionMajor;
		int versionMinor;
		glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
		glGetIntegerv(GL_MINOR_VERSION, &versionMinor);

		HZ_CORE_ASSERT(versionMajor > 4 ||(versionMajor == 4 && versionMinor >= 5), "Hazel requires at least OpenGL version!");
	#endif
	}

	void OpenGLContext::SwapBuffers()
	{
		HZ_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}
}