#pragma once

#include <Hazel.h>
#include "Panels/SceneHierarchyPanel.h"
#include "Hazel/Renderer/EditorCamera.h"

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
	bool OnMouseButtonPressed(MouseButtonPressedEvent& e);

	void NewScene();
	void OpenScene();
	void SaveSceneAs();
private:
	Ref<Framebuffer> m_Framebuffer;

	Ref<Scene> m_ActiveScene;

	Entity m_HoveredEntity;

	EditorCamera m_EditorCamera;

	bool m_ViewportFocused = false;
	bool m_ViewportHovered = false;
	glm::vec2 m_ViewportSize = { 0.0f, 0.0f };
	glm::vec2 m_ViewportBounds[2];

	int m_GizmoType = -1;

	// Panels
	SceneHierarchyPanel m_SceneHierarchyPanel;
};

}

