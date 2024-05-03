extends Node

onready var getUserAchievementsButton: Button = $"PanelContainer/VBoxContainer/ButtonGetUserAchievements"
onready var backButton: Button = $"PanelContainer/VBoxContainer/ButtonBack"

func _ready():
	getUserAchievementsButton.connect("pressed", self, "_getUserAchievementsButtonPressed")
	backButton.connect("pressed", self, "_backButtonPressed")

func _getUserAchievementsButtonPressed():
	_getLoadingPanelNode().show_panel()
	$AchievementModule.getUserAchievementsAsync(
		RGNCore.getUserId(),
		false,
		0,
		10,
		funcref(self, "_onGetUserAchievementsSuccess"),
		funcref(self, "_onGetUserAchievementsFail")
	)

func _onGetUserAchievementsSuccess(userAchievements):
	_getLoadingPanelNode().hide_panel()
	_getMessagePanelNode().show_panel("Success", JSON.print(userAchievements))
	
func _onGetUserAchievementsFail(_errorCode, errorMessage):
	_getLoadingPanelNode().hide_panel()
	_getMessagePanelNode().show_panel("Error", errorMessage)

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
