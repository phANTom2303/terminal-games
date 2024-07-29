
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
    let header = document.querySelector(".header");
    renderComponent(header, 50);
    let cards = document.querySelectorAll(".card");
    for (let card of cards) {
        renderComponent(card, 1);
    }
    let footer = document.querySelector(".footer");
    renderComponent(footer, 15);
}

render();
