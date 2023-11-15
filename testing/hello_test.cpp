#include <gtest/gtest.h>
#include "maths/vec3.h"

TEST(Vector3, ExpectedConstruction) {
	Vec3 expectedVector(-1.4f, 0.0f, 975.0f);

	EXPECT_FLOAT_EQ(expectedVector.x(), -1.4f);
	EXPECT_FLOAT_EQ(expectedVector.y(), 0.0f);
	EXPECT_FLOAT_EQ(expectedVector.z(), 975.0f);
}