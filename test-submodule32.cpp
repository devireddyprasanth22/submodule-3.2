#include <gtest/gtest.h>
#include <cstdio>
#include <cstdlib>
#include <string>

// Function to capture stdout from a command
std::string captureStdout(const char *command) {
    char buffer[128];
    std::string result = "";
    FILE *pipe = popen(command, "r");
    if (!pipe) return "ERROR";
    while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
        result += buffer;
    }
    pclose(pipe);
    return result;
}

TEST(Submodule32Test, PrintTest) {
    std::string output = captureStdout("./submodule32");
    EXPECT_EQ(output, "Hello from submodule3.2\n");
}

// Main function for Google Test
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
