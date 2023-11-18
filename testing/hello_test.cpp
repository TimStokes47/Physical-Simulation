#include <gtest/gtest.h>
#include <gtest/gtest-matchers.h>
#include "maths/vec3.h"
#include "maths/mat4.h"

TEST(Vector3, ExpectedConstruction) {
	Vec3 expectedVector(-1.4f, 0.0f, 975.0f);

	EXPECT_FLOAT_EQ(expectedVector.x(), -1.4f);
	EXPECT_FLOAT_EQ(expectedVector.y(), 0.0f);
	EXPECT_FLOAT_EQ(expectedVector.z(), 975.0f);
}

TEST(Mat4, DefaultConstruction) {
	Mat4 identity;
	
	EXPECT_FLOAT_EQ(identity.getRow(0)[0], 1.0f);
	EXPECT_FLOAT_EQ(identity.getRow(1)[1], 1.0f);
	EXPECT_FLOAT_EQ(identity.getRow(2)[2], 1.0f);
	EXPECT_FLOAT_EQ(identity.getRow(3)[3], 1.0f);
}