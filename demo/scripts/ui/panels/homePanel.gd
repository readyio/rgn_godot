extends Node

onready var userNameLabel: Label = $"PanelContainer/VBoxContainer/VBoxContainer/VBoxContainer/UserNameLabel"
onready var currencyButton: Button = $"PanelContainer/VBoxContainer/VBoxContainer/ButtonCurrency"
onready var inventoryButton: Button = $"PanelContainer/VBoxContainer/VBoxContainer/ButtonInventory"
onready var achievementsButton: Button = $"PanelContainer/VBoxContainer/VBoxContainer/ButtonAchievements"
onready var storeButton: Button = $"PanelContainer/VBoxContainer/VBoxContainer/ButtonStore"
onready var walletsButton: Button = $"PanelContainer/VBoxContainer/VBoxContainer/ButtonWallets"
onready var userProfileButton: Button = $"PanelContainer/VBoxContainer/VBoxContainer/ButtonUserProfile"
onready var signOutButton: Button = $"PanelContainer/VBoxContainer/ButtonSignOut"

func _ready():
	currencyButton.connect("pressed", self, "_onCurrencyButtonPressed")
	inventoryButton.connect("pressed", self, "_onInventoryButtonPressed")
	achievementsButton.connect("pressed", self, "_onAchievementsButtonPressed")
	storeButton.connect("pressed", self, "_onStoreButtonPressed")
	walletsButton.connect("pressed", self, "_onWalletsButtonPressed")
	userProfileButton.connect("pressed", self, "_onUserProfileButtonPressed")
	signOutButton.connect("pressed", self, "_onSignOutButtonPressed")

func _onCurrencyButtonPressed():
	hide_panel()
	_getCurrencyPanelNode().show_panel()

func _onInventoryButtonPressed():
	hide_panel()
	_getInventoryPanelNode().show_panel()

func _onAchievementsButtonPressed():
	hide_panel()
	_getAchievementsPanelNode().show_panel()

func _onStoreButtonPressed():
	hide_panel()
	_getStorePanelNode().show_panel()

func _onWalletsButtonPressed():
	hide_panel()
	_getWalletsPanelNode().show_panel()

func _onUserProfileButtonPressed():
	hide_panel()
	_getUserProfilePanelNode().show_panel()

func _onSignOutButtonPressed():
	RGNCore.signOut()

func _setUserName(userName: String):
	userNameLabel.text = userName
	
func _loadUserName():
	if (!RGNCore.getUserId().empty()):
		userNameLabel.text = "Loading..."
		$UserProfileModule.getProfileAsync_UserId(RGNCore.getUserId(),
			funcref(self, "_onGetProfileSuccess"),
			funcref(self, "_onGetProfileFail")
		)

func _onGetProfileSuccess(userData):
	userNameLabel.text = userData.displayName
	
func _onGetProfileFail(errorCode, errorMessage):
	print("[UserProfileModule-GetProfile] Error, code: " + errorCode.to_string() + ", message: " + errorMessage)

func _getCurrencyPanelNode():
	return get_tree().root.get_node("Node2D/CanvasLayer/Panels/CurrencyPanel")

func _getInventoryPanelNode():
	return get_tree().root.get_node("Node2D/CanvasLayer/Panels/InventoryPanel")

func _getAchievementsPanelNode():
	return get_tree().root.get_node("Node2D/CanvasLayer/Panels/AchievementsPanel")
	
func _getStorePanelNode():
	return get_tree().root.get_node("Node2D/CanvasLayer/Panels/StorePanel")

func _getWalletsPanelNode():
	return get_tree().root.get_node("Node2D/CanvasLayer/Panels/WalletsPanel")

func _getUserProfilePanelNode():
	return get_tree().root.get_node("Node2D/CanvasLayer/Panels/UserProfilePanel")

func show_panel():
	self.visible = true
	_loadUserName()

func hide_panel():
	self.visible = false
