extends Node

@onready var userNameTextEdit: TextEdit = $"PanelContainer/VBoxContainer/VBoxContainer/UserNameChangeContainer/UserNameTextEdit"
@onready var applyUserNameButton: Button = $"PanelContainer/VBoxContainer/VBoxContainer/UserNameChangeContainer/ButtonApply"
@onready var backButton: Button = $"PanelContainer/VBoxContainer/VBoxContainer/ButtonBack"

func _ready():
	applyUserNameButton.connect("pressed", _applyUserNameButtonPressed)
	backButton.connect("pressed", _backButtonPressed)

func _applyUserNameButtonPressed():
	_getLoadingPanelNode().show_panel()
	UserProfileModule.setDisplayNameAsync(
		userNameTextEdit.text,
		func (_response):
			_getLoadingPanelNode().hide_panel(),
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