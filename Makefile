CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude
LDFLAGS = 
SRC_DIR = src
INCLUDE_DIR = include
TESTS_DIR = tests
BUILD_DIR = build
BIN_DIR = bin

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))
DEPS = $(wildcard $(INCLUDE_DIR)/*.h)

TEST_SRCS = $(wildcard $(TESTS_DIR)/*.cpp)
TEST_OBJS = $(filter-out $(BUILD_DIR)/main.o, $(OBJS))
TEST_EXE = $(BIN_DIR)/runTests

MAIN_EXE = $(BIN_DIR)/tic_tac_toe

all: $(MAIN_EXE) tests

$(MAIN_EXE): $(OBJS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(DEPS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

tests: $(TEST_EXE)

$(TEST_EXE): $(TEST_OBJS) $(TEST_SRCS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) $(TEST_SRCS) $(TEST_OBJS) -o $@ $(LDFLAGS) -lgtest -lgtest_main -lpthread

run_tests: tests
	$(TEST_EXE)

clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

doc:
	doxygen Doxyfile

.PHONY: all clean tests run_tests doc
