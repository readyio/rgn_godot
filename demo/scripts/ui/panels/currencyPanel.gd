extends Node

@onready var getUserCurrenciesButton: Button = $"PanelContainer/VBoxContainer/VBoxContainer/ButtonGetUserCurrencies"
@onready var backButton: Button = $"PanelContainer/VBoxContainer/VBoxContainer/ButtonBack"

func _ready():
	getUserCurrenciesButton.connect("pressed", _getUserCurrenciesButtonPressed)
	backButton.connect("pressed", _backButtonPressed)

func _getUserCurrenciesButtonPressed():
	_getLoadingPanelNode().show_panel()
	CurrencyModule.getUserCurrenciesAsync(
		func (userCurrencies):
			_getLoadingPanelNode().hide_panel()
			_getMessagePanelNode().show("Success", JSON.stringify(userCurrencies)),
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
