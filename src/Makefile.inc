APPL_COBJS +=

APPL_CXXOBJS += \
    StartUp.o \
    Starter.o \
    Contest.o \
    display.o \
    Touch.o \
    CountDetection.o \
    TimeDetection.o \
    KunokunoMotors.o \
    Arm.o \
    BubbleSort.o \
    SelectionSort.o \
    QuickSort.o \
    Move.o \
    Color.o \
    SelectionSortCource.o \
    ShuffleCource.o \
    BubbleSortCource.o \
    QuickSortCource.o \
    ICource.o \

SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
include $(WORKSPACE_LIB_DIR)/libcpp-ev3/Makefile

endif
