extends Node

onready var signInButton: Button = $"PanelContainer/VBoxContainer/ButtonSignIn"
onready var guestSignInButton: Button = $"PanelContainer/VBoxContainer/ButtonGuestSignIn"

func _ready():
	signInButton.connect("pressed", self, "_onSignInButtonPressed")
	guestSignInButton.connect("pressed", self, "_onGuestSignInButtonPressed")
	RGNCore.bindAuthChangeCallback(funcref(self, "_onSignInEvent"))

func _onSignInButtonPressed():
	_getLoadingPanelNode().show_panel()
	RGNCore.signIn()

func _onGuestSignInButtonPressed():
	_getLoadingPanelNode().show_panel()
	RGNCore.signInAnonymously()

func _onSignInEvent(isLoggedIn: bool):
	_getLoadingPanelNode().hide_panel()
	if (isLoggedIn):
		hide_panel()
		_getHomePanelNode().show_panel()

func _getHomePanelNode():
	return get_tree().root.get_node("Node2D/CanvasLayer/Panels/HomePanel")

func _getLoadingPanelNode():
	return get_tree().root.get_node("Node2D/CanvasLayer/LoadingPanel")

func show_panel():
	self.visible = true

func hide_panel():
	self.visible = false
