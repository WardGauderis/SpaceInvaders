//
// Created by ward on 12/8/19.
//

#include "physicalEntity.h"

SI::controller::PhysicalEntity::PhysicalEntity(std::weak_ptr<model::PhysicalEntity> model,
                                               std::weak_ptr<view::PhysicalEntity> view)
    : model(std::move(model)), view(std::move(view))
{
}

std::pair<std::shared_ptr<SI::model::PhysicalEntity>, std::shared_ptr<SI::view::PhysicalEntity>>
SI::controller::PhysicalEntity::lock()
{
        auto m = PhysicalEntity::model.lock();
        auto v = PhysicalEntity::view.lock();
        if (!m || !v || m->mayDeleteThis() || v->mayDeleteThis())
                deleteThis();
        return {m, v};
}
