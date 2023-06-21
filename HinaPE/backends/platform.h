#ifndef BACKENDS_PLATFORM_H
#define BACKENDS_PLATFORM_H

// Copyright (c) 2023 Xayah Hina
// MPL-2.0 license

#include <string>
#include <utility>
#include <vector>
#include <map>
#include <functional>
#include <memory>
#include <tuple>
#include <array>
#include <stdexcept>

#include "common.h"

namespace Kasumi
{
class Platform : public NoCopyAndMove
{
public:
	static auto Init() -> void;
	static auto NewWindow(int width, int height, const std::string &title) -> int; // return the window ID
	static auto KillWindow(int window_id) -> void;
	static auto SetCurrentWindow(int window_id) -> void;

	static class GLFWwindow *CURRENT_WINDOW;
	static std::vector<class GLFWwindow *> WINDOWS;

private:
	static auto _CheckValid(int window_id) -> bool;
};
}

#endif //BACKENDS_PLATFORM_H
