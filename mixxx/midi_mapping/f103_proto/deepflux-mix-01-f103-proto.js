var DeepFluxMIX01 = {};

DeepFluxMIX01.backButton = function(_channel, _control, value, _status, group){

    if(value === 0) {return;}

    var focus = engine.getValue(group, "focused_widget");

    if(focus === 2){
        engine.setValue(group, "focused_widget", 3);
    }
    else if(focus === 3){
        engine.setValue(group, "focused_widget", 2);
    }
};