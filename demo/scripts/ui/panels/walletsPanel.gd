extends Node

@onready var createWalletButton: Button = $"PanelContainer/VBoxContainer/VBoxContainer/ButtonCreateWallet"
@onready var backButton: Button = $"PanelContainer/VBoxContainer/VBoxContainer/ButtonBack"

func _ready():
	createWalletButton.connect("pressed", _createWalletButtonPressed)
	backButton.connect("pressed", _backButtonPressed)

func _createWalletButtonPressed():
	RGNCore.createWallet()

func _backButtonPressed():
	hide_panel()
	_getHomePanelNode().show_panel()

func _getHomePanelNode():
	return get_tree().root.get_node("Node2D/CanvasLayer/Panels/HomePanel")

func show_panel():
	self.visible = true

func hide_panel():
	self.visible = false
