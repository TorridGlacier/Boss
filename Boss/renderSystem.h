#pragma once
#include <anax/anax.hpp>
#include <Components.h>
#include <Constants.h>
#include <iostream>
using namespace anax;

#ifndef RENDER_SYSTEM
#define RENDER_SYSTEM



struct RenderSystem : System<Requires<PositionComponent, RectComponent>>
{
	void process(Entity& e, double deltaTime)
	{
		PositionComponent& positionComp = e.getComponent<PositionComponent>();
		RectComponent& rectComponent = e.getComponent<RectComponent>();
		// translate the object
		rectComponent.rect.setPosition(positionComp.position);

		render(rectComponent.rect);

	}

	void update(double deltaTime)
	{
		auto entities = getEntities();

		WINDOW.clear();
		WINDOW.setView(VIEW);
		
		for (auto i : entities)
		{
			process(i, deltaTime);
		}
		WINDOW.display();
	}


	void render(sf::RectangleShape rect) 
	{
		WINDOW.draw(rect);
	}

};

#endif // RENDER_SYSTEM