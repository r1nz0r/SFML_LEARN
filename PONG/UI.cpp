#include <cassert>
#include <SFML/Graphics/RenderWindow.hpp>
#include "UI.h"
#include "Constants.h"

void InitializeLabel(Label& label, const Position2D& position)
{
	assert(label.textFont.loadFromFile(RESOURCES_PATH + FONT_NAME));
	label.text.setFont(label.textFont);
	label.text.setCharacterSize(label.textSize);
	label.text.setString("0");
	label.text.setPosition(position);
	label.text.setFillColor(label.color);
}

void DrawLabel(const Label& label, sf::RenderWindow& window)
{
	window.draw(label.text);
}

void OnLabelChange(Label& label, const std::string& text)
{
	label.text.setString(text);
}
