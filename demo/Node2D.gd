extends Node2D

var keyQ = false
var keyW = false

# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	G_RGNUpdater.update()
	if Input.is_physical_key_pressed(KEY_Q) && keyQ == false:
		keyQ = true
		print("Key Q is pressed")
		G_RGNCore.test_write()
	if Input.is_physical_key_pressed(KEY_W) && keyW == false:
		keyW = true
		print("Key W is pressed")
		G_RGNCore.test_read()
	pass
