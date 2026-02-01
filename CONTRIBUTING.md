# Contributing to TENS-System

Thank you for your interest in contributing to the TENS-System project! This document provides guidelines and information for contributors.

## 📋 Table of Contents

- [Code of Conduct](#code-of-conduct)
- [How Can I Contribute?](#how-can-i-contribute)
- [Getting Started](#getting-started)
- [Development Setup](#development-setup)
- [Submitting Changes](#submitting-changes)
- [Style Guidelines](#style-guidelines)
- [Reporting Issues](#reporting-issues)

## 📜 Code of Conduct

By participating in this project, you agree to maintain a respectful and inclusive environment. Please:

- Be respectful and considerate in your interactions
- Welcome newcomers and help them learn
- Accept constructive criticism gracefully
- Focus on what is best for the community

## 🤝 How Can I Contribute?

### Types of Contributions

1. **Code Contributions**
   - Bug fixes
   - New features
   - Performance improvements
   - Code refactoring

2. **Documentation**
   - Improve existing documentation
   - Write tutorials
   - Add code comments
   - Translate documentation

3. **Hardware**
   - Improve circuit designs
   - Design new enclosures
   - Test with different components
   - Create assembly guides

4. **Testing**
   - Test the device
   - Report bugs
   - Verify fixes
   - Test on different Arduino boards

5. **Community**
   - Answer questions
   - Help other users
   - Share the project

## 🚀 Getting Started

### Prerequisites

Before contributing, ensure you have:

- Git installed on your system
- Arduino IDE (version 1.8.x or later)
- Basic understanding of Arduino programming
- (Optional) 3D modeling software for enclosure contributions

### Fork and Clone

1. Fork the repository on GitHub
2. Clone your fork locally:
   ```bash
   git clone https://github.com/YOUR_USERNAME/TENS-System.git
   cd TENS-System
   ```
3. Add the upstream remote:
   ```bash
   git remote add upstream https://github.com/kershrita/TENS-System.git
   ```

## 💻 Development Setup

### Arduino Development

1. Open `core-device/core-device.ino` in Arduino IDE
2. Install any required libraries via **Sketch > Include Library > Manage Libraries**
3. Select your board and port
4. Make your changes
5. Verify the code compiles without errors
6. Test on actual hardware if possible

### 3D Model Development

For 3D enclosure contributions:
- Use industry-standard formats (STL, STEP)
- Ensure models are manifold (watertight)
- Test prints before submitting
- Include printing parameters in your PR

## 📤 Submitting Changes

### Branch Naming

Use descriptive branch names:
- `feature/add-new-mode` - for new features
- `fix/serial-timing` - for bug fixes
- `docs/update-readme` - for documentation
- `hardware/new-enclosure` - for hardware changes

### Commit Messages

Write clear, concise commit messages:

```
type: short description

Longer description if needed, explaining the what and why.

- Bullet points for multiple changes
- Keep lines under 72 characters
```

Types: `feat`, `fix`, `docs`, `style`, `refactor`, `test`, `chore`

### Pull Request Process

1. **Update your fork** with the latest upstream changes:
   ```bash
   git fetch upstream
   git rebase upstream/main
   ```

2. **Create a feature branch**:
   ```bash
   git checkout -b feature/your-feature
   ```

3. **Make your changes** and commit them

4. **Push to your fork**:
   ```bash
   git push origin feature/your-feature
   ```

5. **Open a Pull Request** on GitHub with:
   - Clear title describing the change
   - Description of what was changed and why
   - Reference to any related issues
   - Screenshots if applicable (especially for hardware/UI changes)

6. **Respond to feedback** and make requested changes

## 📝 Style Guidelines

### Arduino/C++ Code

- Use meaningful variable names
- Add comments for complex logic
- Keep functions focused and small
- Use `#define` for pin assignments
- Follow existing code style in the project

```cpp
// Good
#define ledPin 13
int sensorValue = 0;

// Avoid
#define L 13
int s = 0;
```

### Documentation

- Use Markdown for documentation
- Include code examples where helpful
- Keep language clear and accessible
- Update the README if your change affects usage

### 3D Models

- Use descriptive file names
- Include basic dimensions in file names if helpful
- Provide printing parameters in comments or separate file

## 🐛 Reporting Issues

When reporting bugs, please include:

1. **Description**: Clear description of the issue
2. **Steps to Reproduce**: How to recreate the problem
3. **Expected Behavior**: What you expected to happen
4. **Actual Behavior**: What actually happened
5. **Environment**:
   - Arduino board type
   - Arduino IDE version
   - Operating system
6. **Screenshots/Photos**: If applicable
7. **Error Messages**: Complete error output if any

### Issue Template

```markdown
## Description
[Describe the issue]

## Steps to Reproduce
1. [First step]
2. [Second step]
3. [...]

## Expected Behavior
[What should happen]

## Actual Behavior
[What actually happens]

## Environment
- Arduino Board: [e.g., Arduino Uno]
- IDE Version: [e.g., 1.8.19]
- OS: [e.g., Windows 10]

## Additional Context
[Any other relevant information]
```

## ❓ Questions?

If you have questions about contributing:

1. Check existing [Issues](https://github.com/kershrita/TENS-System/issues) for answers
2. Open a new issue with the "question" label
3. Reach out to the maintainers

## 🙏 Thank You!

Your contributions help make this project better for everyone. Whether it's fixing a typo, adding a feature, or improving documentation - every contribution matters!

---

*Happy Contributing! 🎉*
