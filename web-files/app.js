function renderComponent(component, delay) {
  let i = 0;
  const html = component.innerHTML;
  function iterate() {
    component.innerHTML = html.slice(0, i + 1);
    i++;
    if (i < html.length) {
      setTimeout(iterate, delay);
    }
  }
  iterate();
}

function render() {
  let header = document.querySelector(".heading-text");
  renderComponent(header, 50);
  let cards = document.querySelectorAll(".card");
  for (let card of cards) {
    renderComponent(card, 1);
  }
  let footer = document.querySelector(".footer");
  renderComponent(footer, 15);
}

render();

document.querySelector(".theme-switch").addEventListener("click", () => {
  const rootElement = document.documentElement;
  const newTheme = rootElement.className === "dark" ? "light" : "dark";
  rootElement.className = newTheme;

  // Get the theme switch image element
  const themeIcon = document.querySelector(".theme-switch");

  // Change the image source based on the new theme
  if (themeIcon) {
    if (newTheme === "light") {
      themeIcon.src =
        "web-files/assets/dark_mode_50dp_333333_FILL0_wght400_GRAD0_opsz48.png"; // Icon to switch to dark mode
      themeIcon.alt = "Switch to Dark Mode";
    } else {
      themeIcon.src =
        "./web-files/assets/light_mode_50dp_FFFFFF_FILL0_wght400_GRAD0_opsz48.png";
      themeIcon.alt = "Switch to Light Mode";
    }
  }
});
