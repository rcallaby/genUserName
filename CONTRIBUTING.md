# Contributing to the repository.

Thank you for considering contributing to genUserName! This project aims to help create a series of unique usernames based on a dictionary or file supplied by the user. The project is written in C.

## Getting Started

### Fork the Repository

1. Fork the repository to your own GitHub account by clicking the "Fork" button.
2. Clone the forked repository to your local machine:

   ```bash
   git clone https://github.com/your-username/genUserName.git
   ```

3. Navigate to the project directory:

   ```bash
   cd genUserName
   ```

### Setting Up Your Environment

Ensure you have the necessary tools to build and run the project:

- A C compiler (e.g., `gcc`)
- `make` (if using a Makefile for building)
- Any necessary dependencies or libraries mentioned in the README

### Building the Project

To build the project, run:

```bash
make
```

This will compile the source files and generate the executable.

## Making Changes

### Branching

Create a new branch for your changes:

```bash
git checkout -b feature/your-feature-name
```

### Code Style

Please adhere to the following coding style guidelines:

- Use consistent indentation (4 spaces).
- Follow the K&R style for braces and formatting.
- Add comments to explain complex logic.
- Ensure your code is well-documented.

### Adding Features or Fixes

1. Make your changes in the new branch.
2. Test your changes thoroughly.
3. If applicable, update or add new tests to cover your changes.
4. Run all tests to ensure nothing is broken:

   ```bash
   make test
   ```

### Commit Messages

Write clear and concise commit messages. Follow the [Conventional Commits](https://www.conventionalcommits.org/en/v1.0.0/) specification:

```
<type>[optional scope]: <description>

[optional body]

[optional footer(s)]
```

Examples:

- `feat(username): add new algorithm for generating unique usernames`
- `fix(parser): handle empty input files without crashing`

### Pushing Changes

Push your changes to your forked repository:

```bash
git push origin feature/your-feature-name
```

## Submitting a Pull Request

1. Navigate to the original repository and click the "New Pull Request" button.
2. Select the branch you created from your forked repository.
3. Provide a clear description of the changes you made and any relevant information.
4. Submit the pull request for review.

## Code Review

- Be open to feedback and suggestions.
- Make necessary changes and update your pull request.
- Ensure all tests pass before the final review.

## Community Guidelines

- Be respectful and considerate of others.
- Follow the [Code of Conduct](CODE_OF_CONDUCT.md) (if applicable).

## Contact

If you have any questions or need further assistance, please open an issue or contact the project maintainers.

Thank you for contributing to genUserName!

---
