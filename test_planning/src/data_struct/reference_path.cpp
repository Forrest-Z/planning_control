#include "data_struct/reference_path.h"

namespace mujianhua {
namespace planning {

ReferencePath::ReferencePath()
    : reference_path_impl_(std::make_shared<ReferencePathImpl>()) {}

void ReferencePath::clear() { return reference_path_impl_->clear(); }

void ReferencePath::SetSpline(const tk::spline &x_s, const tk::spline &y_s,
                              double max_s) {
    return reference_path_impl_->SetSpline(x_s, y_s, max_s);
}

const tk::spline &ReferencePath::GetXS() const {
    return reference_path_impl_->GetXS();
}

const tk::spline &ReferencePath::GetYS() const {
    return reference_path_impl_->GetYS();
}

double ReferencePath::GetXS(double s) const {
    return reference_path_impl_->GetXS()(s);
}
double ReferencePath::GetYS(double s) const {
    return reference_path_impl_->GetYS()(s);
}

double ReferencePath::GetLength() const {
    return reference_path_impl_->GetLength();
}

void ReferencePath::SetLength(double s) {
    return reference_path_impl_->SetLength(s);
}

} // namespace planning
} // namespace mujianhua
