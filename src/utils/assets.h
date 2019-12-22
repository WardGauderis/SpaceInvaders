//
// Created by ward on 12/22/19.
//

#ifndef SPACEINVADERS_ASSETS_H
#define SPACEINVADERS_ASSETS_H

#include <SFML/Audio/Music.hpp>
#include <memory>
#include <SFML/Graphics/Font.hpp>

namespace utils {

	class Assets {
	public:
		static Assets& get();

		Assets(const Assets&) = delete;

		Assets& operator=(const Assets&) = delete;

		[[nodiscard]] const std::shared_ptr<sf::Music>& getMusic() const;

		[[nodiscard]] const std::shared_ptr<sf::Font>& getBold() const;

		[[nodiscard]] const std::shared_ptr<sf::Font>& getNormal() const;

	private:
		const std::shared_ptr<sf::Music> music;
		const std::shared_ptr<sf::Font> bold;
		const std::shared_ptr<sf::Font> normal;

		Assets();

		~Assets() = default;
	};

}

#endif //SPACEINVADERS_ASSETS_H
