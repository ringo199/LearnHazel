#include <Hazel.h>
// ---Entry Point---------------------
#include <Hazel/Core/EntryPoint.h>
// -----------------------------------

#include "EditorLayer.h"

class Hazelnut : public Hazel::Application
{
public:
	Hazelnut()
		: Application("Hazelnut")
	{
		PushLayer(new Hazel::EditorLayer());
	}

	~Hazelnut()
	{
	}
};

Hazel::Application *Hazel::CreateApplication()
{
	return new Hazelnut();
}
