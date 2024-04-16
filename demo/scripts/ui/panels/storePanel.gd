extends Node

@onready var itemIdTextEdit: TextEdit = $"PanelContainer/VBoxContainer/VBoxContainer/ItemIdInputContainer/ItemIdTextEdit"
@onready var buyButton: Button = $"PanelContainer/VBoxContainer/VBoxContainer/ButtonBuy"
@onready var backButton: Button = $"PanelContainer/VBoxContainer/VBoxContainer/ButtonBack"

func _ready():
	buyButton.connect("pressed", _buyButtonPressed)
	backButton.connect("pressed", _backButtonPressed)

func _buyButtonPressed():
	_getLoadingPanelNode().show_panel()
	StoreModule.buyVirtualItemsAsync(
		[itemIdTextEdit.text],
		[],
		"",
		func (buyResponse):
			_getLoadingPanelNode().hide_panel()
			_getMessagePanelNode().show("Success", JSON.stringify(buyResponse)),
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