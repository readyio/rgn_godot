extends Node

@onready var addToInventoryButton: Button = $"PanelContainer/VBoxContainer/VBoxContainer/ButtonAddToInventory"
@onready var getUserInventoryButton: Button = $"PanelContainer/VBoxContainer/VBoxContainer/ButtonGetUserInventory"
@onready var backButton: Button = $"PanelContainer/VBoxContainer/VBoxContainer/ButtonBack"

func _ready():
    addToInventoryButton.connect("pressed", _addToInventoryButtonPressed)
    getUserInventoryButton.connect("pressed", _getUserInventoryButtonPressed)
    backButton.connect("pressed", _backButtonPressed)

func _addToInventoryButtonPressed():
    hide_panel()
    _getAddItemToInventoryPanelNode().show_panel()

func _getUserInventoryButtonPressed():
    _getLoadingPanelNode().show_panel()
    InventoryModule.getAllForCurrentAppAsync(
		func (userItems):
            _getLoadingPanelNode().hide_panel()
            _getMessagePanelNode().show_panel("Success", JSON.stringify(userItems)),
		func (_errorCode, errorMessage):
            _getLoadingPanelNode().hide_panel()
            _getMessagePanelNode().show_panel("Error", errorMessage)
    )

func _backButtonPressed():
    hide_panel()
    _getHomePanelNode().show_panel()

func _getHomePanelNode():
    return get_tree().root.get_node("Node2D/CanvasLayer/Panels/HomePanel")

func _getMessagePanelNode():
    return get_tree().root.get_node("Node2D/CanvasLayer/Panels/MessagePanel")

func _getAddItemToInventoryPanelNode():
    return get_tree().root.get_node("Node2D/CanvasLayer/Panels/AddItemToInventoryPanel")

func _getLoadingPanelNode():
    return get_tree().root.get_node("Node2D/CanvasLayer/LoadingPanel")

func show_panel():
    self.visible = true

func hide_panel():
    self.visible = false