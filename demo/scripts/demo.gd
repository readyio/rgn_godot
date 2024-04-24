extends Node

@onready var loadingPanel: Panel = $"CanvasLayer/LoadingPanel"
@onready var messagePanel: Panel = $"CanvasLayer/Panels/MessagePanel"
@onready var signInPanel: Panel = $"CanvasLayer/Panels/SignInPanel"
@onready var homePanel: Panel = $"CanvasLayer/Panels/HomePanel"
@onready var currencyPanel: Panel = $"CanvasLayer/Panels/CurrencyPanel"
@onready var inventoryPanel: Panel = $"CanvasLayer/Panels/InventoryPanel"
@onready var addItemToInventoryPanel: Panel = $"CanvasLayer/Panels/AddItemToInventoryPanel"
@onready var achievementsPanel: Panel = $"CanvasLayer/Panels/AchievementsPanel"
@onready var storePanel: Panel = $"CanvasLayer/Panels/StorePanel"
@onready var userProfilePanel: Panel = $"CanvasLayer/Panels/UserProfilePanel"
@onready var walletsPanel: Panel = $"CanvasLayer/Panels/WalletsPanel"

func _ready():
	_initReady()
	_showNextPanel()

func _process(_delta):
	RGNCore.update()

func _initReady():
	var configure_data = G_RGNConfigurationData.new()
	configure_data.setAppId("io.getready.rgntest")
	configure_data.setEnvironmentTarget(G_RGNEnvironmentTarget.DEVELOPMENT)
	RGNCore.initialize(self, configure_data)
	RGNCore.bindAuthChangeCallback(_onAuthChange)

func _onAuthChange(isLoggedIn:):
	if (!isLoggedIn):
		_hideAllPanels()
		signInPanel.show_panel()

func _showNextPanel():
	_hideAllPanels()
	if (RGNCore.isLoggedIn()):
		homePanel.show_panel()
	else:
		signInPanel.show_panel()

func _hideAllPanels():
	loadingPanel.hide_panel()
	messagePanel.hide_panel()
	signInPanel.hide_panel()
	homePanel.hide_panel()
	currencyPanel.hide_panel()
	inventoryPanel.hide_panel()
	addItemToInventoryPanel.hide_panel()
	achievementsPanel.hide_panel()
	storePanel.hide_panel()
	userProfilePanel.hide_panel()
	walletsPanel.hide_panel()
