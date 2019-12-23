//
// Created by ward on 12/22/19.
//

#ifndef SPACEINVADERS_ASSETS_H
#define SPACEINVADERS_ASSETS_H

#include <SFML/Audio/Music.hpp>
#include <SFML/Graphics/Font.hpp>
#include <memory>

namespace utils {

	/**
	 * class that handles assets (singleton)
	 */
	class Assets {
	public:

		/**
		 * Meyer's singleton pattern constructor
		 * @return the singleton Assets
		 */
		static Assets& get();

		Assets(const Assets&) = delete;

		Assets& operator=(const Assets&) = delete;

		/**
		 * access the game music
		 * @return SFML music object
		 */
		[[nodiscard]] const std::shared_ptr<sf::Music>& getMusic() const;

		/**
		 * access the bold game font
		 * @return SFML font object
		 */
		[[nodiscard]] const std::shared_ptr<sf::Font>& getBold() const;

		/**
		 * access the normal game font
		 * @return SFML font object
		 */
		[[nodiscard]] const std::shared_ptr<sf::Font>& getNormal() const;

	private:
		const std::shared_ptr<sf::Music> music;
		const std::shared_ptr<sf::Font> bold;
		const std::shared_ptr<sf::Font> normal;

		/**
		 * private constructor that opens the required files
		 */
		Assets();

		~Assets() = default;
	};

}

#endif //SPACEINVADERS_ASSETS_H
