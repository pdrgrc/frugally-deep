// Copyright 2016, Tobias Hermann.
// https://github.com/Dobiasd/frugally-deep
// Distributed under the MIT License.
// (See accompanying LICENSE file or at
//  https://opensource.org/licenses/MIT)

#pragma once

#include "fdeep/layers/activation_layer.hpp"

namespace fdeep { namespace internal
{

class sigmoid_layer : public activation_layer
{
public:
    explicit sigmoid_layer(const std::string& name)
        : activation_layer(name)
    {
    }
protected:
    static float_type activation_function(float_type x)
    {
        return 1 / (1 + std::exp(-x));
    };
    tensor3 transform_input(const tensor3& in_vol) const override
    {
        return transform_tensor3(activation_function, in_vol);
    }
};

} } // namespace fdeep, namespace internal
