#pragma once

#include <Hazel.h>
#include "Panels/SceneHierarchyPanel.h"

namespace Hazel
{

class EditorLayer : public Layer
{
public:
	EditorLayer();
	virtual ~EditorLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	virtual void OnUpdate(Timestep ts) override;
	virtual void OnImGuiRender() override;
	virtual void OnEvent(Event& e) override;
private:
	bool OnKeyPressed(KeyPressedEvent& e);

	void NewScene();
	void OpenScene();
	void SaveSceneAs();
private:
	Ref<Framebuffer> m_Framebuffer;

	Ref<Scene> m_ActiveScene;

	bool m_ViewportForced = false;
	bool m_ViewportHovered = false;
	glm::vec2 m_ViewportSize = { 0.0f, 0.0f };

	// Panels
	SceneHierarchyPanel m_SceneHierarchyPanel;
};

}

