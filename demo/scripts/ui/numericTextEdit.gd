extends TextEdit

onready var regex = RegEx.new()

func _ready():
	regex.compile("[0-9]")
	connect("text_changed", self, "_text_changed")

func _text_changed():
	var final_text = ""
	var result = regex.search(text)
	while result != null:
		final_text += result.get_string()
		result = regex.search(text, result.get_end())
	text = final_text
	cursor_set_column(text.length())
