
function render(component) {
    let i = 0;
    const html = component.innerHTML;
    function iterate() {
        component.innerHTML = html.slice(0, i + 1);
        i++;
        if (i < html.length) {
            setTimeout(iterate, 1);
        }
    }
    iterate();
}

let cards = document.querySelectorAll(".card");
for (let card of cards) {
    render(card);
}

