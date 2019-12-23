//
// Created by ward on 11/19/19.
//

#ifndef SPACEINVADERS_ENTITYMODEL_H
#define SPACEINVADERS_ENTITYMODEL_H

#include <random>

#include "../utils/observer.h"

namespace SI::model {
/**
 * abstract class for models
 */
class Entity : public utils::Subject
{
public:
        /**
         * default constructor
         */
        Entity();

        /**
         * abstract function that is ran when the model is updated
         */
        virtual void update() = 0;

        /**
         * poll whether the object wants to add new models to the world
         * @return vector of models
         */
        virtual std::vector<std::shared_ptr<Entity>> getNewModels();

        /**
         * check whether the object may be deleted
         */
        [[nodiscard]] bool mayDeleteThis() const;

        /**
         * indicate that the object may be deleted
         */
        virtual void deleteThis();

        virtual ~Entity() = default;

protected:
        /**
         * get an exception safe static generator
         * @return generator
         */
        static std::default_random_engine& generator();

        /**
         * indicate that a model must be added to the world
         * @param model new model
         */
        void addModel(const std::shared_ptr<Entity>& model);

        /**
         * indicate that multiple models must be added to the world
         * @param models vector of new models
         */
        void addModels(const std::vector<std::shared_ptr<Entity>>& models);

private:
        std::vector<std::shared_ptr<Entity>> newModels;
        bool mustDelete;
};

} // namespace SI::model

#endif // SPACEINVADERS_ENTITYMODEL_H
