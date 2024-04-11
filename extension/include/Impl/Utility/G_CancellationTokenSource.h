#pragma once

#include "Utility/CancellationToken.h"
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/string.hpp>
#include <godot_cpp/variant/dictionary.hpp>
#include <godot_cpp/variant/callable.hpp>
#include <functional>
#include <vector>

class G_CancellationTokenSource : public godot::Object
{
	GDCLASS(G_CancellationTokenSource, godot::Object);
	bool _isCancellationRequested = false;
protected:
	static void _bind_methods() {
		godot::ClassDB::bind_method(godot::D_METHOD("cancel"), &G_CancellationTokenSource::cancel);
		godot::ClassDB::bind_method(godot::D_METHOD("isCancellationRequested"), &G_CancellationTokenSource::isCancellationRequested);
	}
public:
	void cancel() {
		_isCancellationRequested = true;
	}
	bool isCancellationRequested() {
		return _isCancellationRequested;
	}
};