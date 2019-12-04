//
// Created by ward on 12/2/19.
//

#ifndef SPACEINVADERS_MODEL_H
#define SPACEINVADERS_MODEL_H

#include "../utils/observer.h"

namespace SI::model {

	class Model : public utils::Subject {
	public:
		Model() = default;

		virtual void update() = 0;
	};

}


#endif //SPACEINVADERS_MODEL_H
