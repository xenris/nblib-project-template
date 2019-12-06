#include "main.hpp"

void main() {
    constexpr uint64_t cpuFreq = 16000000;

    using Timer = nblib::hw::Timer1;
    using LedPin = nblib::hw::PortB::Pin5;
    using Sleep = nblib::hw::Sleep;

    Timer::waveform(Timer::Waveform::ctcOcra);
    Timer::OutputA::intEnable(true);
    Timer::OutputA::value(cpuFreq / (256 * 2));
    Timer::clock(Timer::Clock::div256);

    LedPin::mode(LedPin::Mode::output);

    Sleep::mode(Sleep::Mode::idle);
    Sleep::enable(true);

    nblib::interruptsEnable(true);

    while(true) {
        Sleep::sleep();

        LedPin::toggle();
    }
}
