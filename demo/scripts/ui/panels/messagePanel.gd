extends Node

@onready var titleLabel: Label = $"VBoxContainer/PanelContainer/MarginContainer/VBoxContainer/TitleLabel"
@onready var messageLabel: RichTextLabel = $"VBoxContainer/PanelContainer/MarginContainer/VBoxContainer/MessageRichTextLabel"
@onready var okButton: Button = $"VBoxContainer/ButtonBackContainer/ButtonOk"

func _ready():
	okButton.connect("pressed", _onOkButtonPressed)

func _onOkButtonPressed():
	hide_panel()

func show(title: String, message: String):
	titleLabel.text = title
	if (message.length() > 600):
		message = message.substr(0, 600) + "..."
	messageLabel.text = "[center]" + message
	self.visible = true

func hide_panel():
	self.visible = false