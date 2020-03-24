//*****************************************************************************
// Copyright 2017-2020 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//*****************************************************************************

#include <cstdint>

#include "concat.hpp"
#include "default_opset.hpp"
#include "exceptions.hpp"
#include "ngraph/op/concat.hpp"
#include "ngraph/validation_util.hpp"

namespace ngraph
{
    namespace onnx_import
    {
        namespace op
        {
            namespace set_1
            {
                NodeVector concat(const Node& node)
                {
                    NodeVector inputs{node.get_ng_inputs()};
                    std::int64_t axis = node.get_attribute_value<std::int64_t>("axis");
                    if (axis < 0)
                    {
                        std::cout << "Concat rank: " << inputs.at(0)->get_output_partial_shape(0).rank().get_length() << std::endl;
                        axis = ngraph::normalize_axis(
                            node.get_description(),
                            axis,
                            inputs.at(0)->get_output_partial_shape(0).rank());
                    }
                    return {std::make_shared<default_opset::Concat>(inputs, axis)};
                }

            } // namespace set_1

        } // namespace op

    } // namespace onnx_import

} // namespace ngraph
