from flask import Flask, request, render_template
from lxml import etree

app = Flask(__name__)


@app.route('/', methods=['GET'])
def index():
    return render_template('index.html')


@app.route('/', methods=['POST'])
def calculate_bmi():
    xml_data = request.data
    try:
        parser = etree.XMLParser(resolve_entities=True)
        doc = etree.fromstring(xml_data, parser)
        Berat = doc.xpath('//berat/text()')[0]
        Tinggi = doc.xpath('//tinggi/text()')[0]

        bmi = calculate_bmi(Berat, Tinggi)
        bmi_category = get_bmi_category(bmi)

        xml_response = f"<response><Tinggi>{Tinggi}</Tinggi><Berat>{Berat}</Berat><result>BMI: {bmi:.2f} ({bmi_category})</result></response>"

        return xml_response, {'Content-Type': 'application/xml'}

    except etree.XMLSyntaxError as e:
        return 'Invalid XML data', 400


def calculate_bmi(berat, tinggi):
    try:
        berat_float = float(berat)
    except ValueError:
        berat_float = 0.0
    
    try:
        tinggi_float = float(tinggi)
    except ValueError:
        tinggi_float = 0.0

    tinggi_meters = tinggi_float / 100  # Convert height to meters
    return berat_float / (tinggi_meters * tinggi_meters)  # Use tinggi_meters here


def get_bmi_category(bmi):
    if bmi < 18.5:
        return 'Underweight'
    elif 18.5 <= bmi < 25:
        return 'Normal weight'
    elif 25 <= bmi < 30:
        return 'Overweight'
    else:
        return 'Obese'


if __name__ == '__main__':
    app.run(host='0.0.0.0', port=80, debug=False)
