extends Node2D

# Called when the node enters the scene tree for the first time.
func _ready():
	G_RGNCore.test()
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	G_RGNUpdater.update()
	pass
