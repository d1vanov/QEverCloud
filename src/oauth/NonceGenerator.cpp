/**
 * Copyright (c) 2023 Dmitry Ivanov
 *
 * This file is a part of QEverCloud project and is distributed under the terms
 * of MIT license: https://opensource.org/licenses/MIT
 */

#include "NonceGenerator.h"

#include <QByteArray>
#include <QRandomGenerator>

namespace qevercloud {

namespace {

[[nodiscard]] quint64 random64()
{
    return QRandomGenerator::securelySeeded().generate64();
}

NonceGenerator nonceGenerator_ = random64;

} // namespace

NonceGenerator nonceGenerator()
{
    return nonceGenerator_;
}

void setNonceGenerator(quint64 (*nonceGenerator)())
{
    nonceGenerator_ = nonceGenerator;
}

} // namespace qevercloud
