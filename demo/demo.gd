extends Node

var configScript = preload("res://addons/rgn/config.gdns")

func _ready():
	var config = configScript.new()
	config.setAppId("io.getready.rgntest")
	config.setDevelopmentEnvironment()
	RGNCore.initialize(config, funcref(self, "_on_initialize"))
	pass
	
func _process(dt):
	RGNCore.update()
	pass

func _on_initialize():
	print("READYgg has been initialized")
	print("UserId is " + RGNCore.getUserId())
	RGNCore.signIn(funcref(self, "_on_signin"))
	
func _on_signin(isLoggedIn):
	$UserProfileModule.getProfileAsync(funcref(self, "_on_get_profile"))
	
func _on_get_profile(response):
	print("User display name is " + response.displayName)
