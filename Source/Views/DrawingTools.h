/*
  ==============================================================================

    DrawingTools.h
    Created: 30 Apr 2018 1:00:13pm
    Author:  Daniel Lindenfelser

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"

class SvgIcon
{
public:
	SvgIcon(const char* data, const size_t size)
	: svg(XmlDocument::parse(String(data, size)))
	{
        drawable = std::unique_ptr<Drawable>(Drawable::createFromSVG(*svg.get()));
	}

	Drawable* getDrawable() {
        return drawable.get();
	}
private:
    std::unique_ptr<XmlElement> svg;
    std::unique_ptr<Drawable> drawable;
};

class Material {
public:
	template <typename T>
	static T convertDpToPixel(Component* c, float dp) {
		auto display = Desktop::getInstance().getDisplays().getDisplayContaining(c->getScreenBounds().getCentre());
		double px = ((dp * 160) / display.dpi);// * display.scale;
		return std::round(T(px));
	}
};