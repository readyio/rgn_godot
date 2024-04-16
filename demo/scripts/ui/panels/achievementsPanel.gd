extends Node

@onready var getUserAchievementsButton: Button = $"PanelContainer/VBoxContainer/VBoxContainer/ButtonGetUserAchievements"
@onready var backButton: Button = $"PanelContainer/VBoxContainer/VBoxContainer/ButtonBack"

func _ready():
	getUserAchievementsButton.connect("pressed", _getUserAchievementsButtonPressed)
	backButton.connect("pressed", _backButtonPressed)

func _getUserAchievementsButtonPressed():
	_getLoadingPanelNode().show_panel()
	AchievementsModule.getUserAchievementsAsync(
		RGNCore.getUserId(),
		false,
		0,
		10,
		func (userAchievements):
			_getLoadingPanelNode().hide_panel()
			_getMessagePanelNode().show("Success", JSON.stringify(userAchievements)),
		func (_errorCode, errorMessage):
			_getLoadingPanelNode().hide_panel()
			_getMessagePanelNode().show("Error", errorMessage)
	)

func _backButtonPressed():
	hide_panel()
	_getHomePanelNode().show_panel()

func _getHomePanelNode():
	return get_tree().root.get_node("Node2D/CanvasLayer/Panels/HomePanel")

func _getMessagePanelNode():
	return get_tree().root.get_node("Node2D/CanvasLayer/Panels/MessagePanel")

func _getLoadingPanelNode():
	return get_tree().root.get_node("Node2D/CanvasLayer/LoadingPanel")

func show_panel():
	self.visible = true

func hide_panel():
	self.visible = false
