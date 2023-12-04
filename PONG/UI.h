#pragma once
#include <SFML/Graphics/Text.hpp>

typedef sf::Vector2f Position2D;

struct Label
{
	bool isVisible = true;
	sf::Text text;
	sf::Font textFont;
	sf::Color color = sf::Color::White;
	unsigned textSize = 30;
};

void InitializeLabel(Label& label, const Position2D& position);
void DrawLabel(const Label& label, sf::RenderWindow& window);
void OnLabelChange(Label& label, const std::string& text);
