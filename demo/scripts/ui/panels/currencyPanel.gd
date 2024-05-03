extends Node

onready var getUserCurrenciesButton: Button = $"PanelContainer/VBoxContainer/ButtonGetUserCurrencies"
onready var backButton: Button = $"PanelContainer/VBoxContainer/ButtonBack"

func _ready():
	getUserCurrenciesButton.connect("pressed", self, "_getUserCurrenciesButtonPressed")
	backButton.connect("pressed", self, "_backButtonPressed")

func _getUserCurrenciesButtonPressed():
	_getLoadingPanelNode().show_panel()
	$CurrencyModule.getUserCurrenciesAsync(
		funcref(self, "_onGetUserCurrenciesSuccess"),
		funcref(self, "_onGetUserCurrenciesFail")
	)
	
func _onGetUserCurrenciesSuccess(userCurrencies):
	_getLoadingPanelNode().hide_panel()
	_getMessagePanelNode().show_panel("Success", JSON.print(userCurrencies))
	
func _onGetUserCurrenciesFail(_errorCode, errorMessage):
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
