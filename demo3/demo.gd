extends Node

var configScript = preload("res://addons/rgn/config.gdns")

func _ready():
	var config = configScript.new()
	config.setAppId("io.getready.rgntest")
	config.setDevelopmentEnvironment()
	READYgg.initialize(config, funcref(self, "_on_initialize"))
	pass
	
func _process(dt):
	READYgg.update()
	pass

func _on_initialize():
	print("READYgg has been initialized")
	print("UserId is " + READYgg.getUserId())
	$UserProfileModule.getProfileAsync(funcref(self, "_on_get_profile"))
	
func _on_get_profile(response):
	print("User display name is " + response.displayName)
