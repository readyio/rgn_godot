#pragma once

#include "Impl/G_Defs.h"
#include "Utility/CancellationToken.h"
#include <functional>
#include <vector>

class G_CancellationTokenSource : public godot::Object
{
	REG_GCLASS(G_CancellationTokenSource, godot::Object);
	bool _isCancellationRequested = false;
public:
	REG_GCLASS_METHODS_HEADER() {
		BIND_GCLASS_METHOD(G_CancellationTokenSource::cancel, GCLASS_METHOD_SIGNATURE("cancel"));
		BIND_GCLASS_METHOD(G_CancellationTokenSource::isCancellationRequested, GCLASS_METHOD_SIGNATURE("isCancellationRequested"));
	}
	void cancel() {
		_isCancellationRequested = true;
	}
	bool isCancellationRequested() {
		return _isCancellationRequested;
	}
};