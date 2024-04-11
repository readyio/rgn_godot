#pragma once

#include "Utility/CancellationToken.h"
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/object.hpp>
#include <functional>
#include <vector>

class G_CancellationToken : public godot::Object
{
	GDCLASS(G_CancellationToken, godot::Object);
	const bool* phandle = false;
protected:
	static void _bind_methods() {
        godot::ClassDB::bind_method(godot::D_METHOD("isCancellationRequested"), &G_CancellationToken::isCancellationRequested);
    }
public:
    void setHandlePtr(const bool* nphandle) {
		phandle = nphandle;
	}
	const bool* getHandlePtr() {
		return phandle;
	}
    bool isCancellationRequested() const {
        if (phandle != nullptr) {
			return *phandle;
		}
		return false;
    }
    static void ConvertToGodotModel(const RGN::CancellationToken& source, G_CancellationToken& target) {
		auto ph = const_cast<RGN::CancellationToken&>(source).GetHandlePtr();
		target.setHandlePtr(ph);
    }
	static void ConvertToCoreModel(const G_CancellationToken& source, RGN::CancellationToken& target) {
		auto ph = const_cast<G_CancellationToken&>(source).getHandlePtr();
		target.SetHandlePtr(ph);
    }
	static void ConvertToCoreModel(godot::Object* source, RGN::CancellationToken& target) {
		if (source == nullptr) {
			return;
		}
		auto ph = cast_to<G_CancellationToken>(source)->getHandlePtr();
		target.SetHandlePtr(ph);
    }
};