#pragma once

#include "Impl/G_Defs.h"
#include "Utility/CancellationToken.h"
#include <functional>
#include <vector>

class G_CancellationToken : public godot::Object
{
	REG_GCLASS(G_CancellationToken, godot::Object);
	const bool* phandle;
public:
	REG_GCLASS_METHODS_HEADER() {
		BIND_GCLASS_METHOD(G_CancellationToken::isCancellationRequested, GCLASS_METHOD_SIGNATURE("isCancellationRequested"));
    }
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