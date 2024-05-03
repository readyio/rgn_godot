extends Node

onready var userIdTextEdit: TextEdit = $"PanelContainer/VBoxContainer/UserIdInputContainer/UserIdTextEdit"
onready var itemIdTextEdit: TextEdit = $"PanelContainer/VBoxContainer/ItemIdInputContainer/ItemIdTextEdit"
onready var quantityTextEdit: TextEdit = $"PanelContainer/VBoxContainer/QuantityInputContainer/QuantityTextEdit"
onready var addButton: Button = $"PanelContainer/VBoxContainer/ButtonAdd"
onready var cancelButton: Button = $"PanelContainer/VBoxContainer/ButtonCancel"

func _ready():
	addButton.connect("pressed", self, "_addButtonPressed")
	cancelButton.connect("pressed", self, "_cancelButtonPressed")

func _addButtonPressed():
	_getLoadingPanelNode().show_panel()
	$InventoryModule.addToInventoryAsync_UserId_VirtualItemId_Quantity_Properties(
		userIdTextEdit.text,
		itemIdTextEdit.text,
		quantityTextEdit.text.to_int(),
		Dictionary(),
		funcref(self, "_onAddToInventorySuccess"),
		funcref(self, "_onAddToInventoryFail")
	)
	
func _onAddToInventorySuccess(response):
	_getLoadingPanelNode().hide_panel()
	_getMessagePanelNode().show_panel("Success", "ItemId: " + response.id + "\n\rItemQuantity: " + str(response.quantity))
	
func _onAddToInventoryFail(_errorCode, errorMessage):
	_getLoadingPanelNode().hide_panel()
	_getMessagePanelNode().show_panel("Error", errorMessage)

func _cancelButtonPressed():
	hide_panel()
	_getInventoryPanelNode().show_panel()

func _getInventoryPanelNode():
	return get_tree().root.get_node("Node2D/CanvasLayer/Panels/InventoryPanel")

func _getMessagePanelNode():
	return get_tree().root.get_node("Node2D/CanvasLayer/Panels/MessagePanel")

func _getLoadingPanelNode():
	return get_tree().root.get_node("Node2D/CanvasLayer/LoadingPanel")

func show_panel():
	userIdTextEdit.text = RGNCore.getUserId()
	self.visible = true

func hide_panel():
	self.visible = false
