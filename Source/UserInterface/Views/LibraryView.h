#pragma once

#include "JuceHeader.h"
#include "../../LookAndFeel/Material.h"

#include "LibraryItem.h"

class LibraryView : public Component
{
public:
    LibraryView() noexcept : Component("LibraryView") {
        table.setColour(ListBox::backgroundColourId, Material::Color::Surface::Base);
        table.setRowHeight(px(LibraryItem::height));
        addAndMakeVisible(table);
    }
    
    ~LibraryView() noexcept override = default;
    
    void resized() override {
        table.setBounds(getLocalBounds());
    }
    
    ListBox table;
private:
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LibraryView)
};
